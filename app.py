import streamlit as st
import sqlite3
import pandas as pd
import matplotlib.pyplot as plt
from datetime import datetime
from PIL import Image
import base64
import openai

# ==============================
# CONFIG
# ==============================
st.set_page_config(page_title="PashuRakshak AI", layout="wide")

st.title("🐄 PashuRakshak AI - Livestock Health Assistant")
st.markdown("AI-powered livestock health monitoring system")

# ==============================
# DATABASE SETUP
# ==============================
conn = sqlite3.connect("livestock.db", check_same_thread=False)
cursor = conn.cursor()

cursor.execute("""
CREATE TABLE IF NOT EXISTS milk_records (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    animal TEXT,
    date TEXT,
    milk REAL
)
""")
conn.commit()

# ==============================
# SIDEBAR
# ==============================
menu = st.sidebar.radio("Navigation", [
    "Disease Prediction",
    "Image Analysis",
    "Milk Tracker",
    "Vaccination Reminder"
])

# ==============================
# SET YOUR OPENAI API KEY HERE
# ==============================
openai.api_key = "YOUR_OPENAI_API_KEY"

# ==============================
# 1️⃣ DISEASE PREDICTION
# ==============================
if menu == "Disease Prediction":

    st.header("🩺 Symptom-based Disease Prediction")

    animal = st.selectbox("Select Animal", ["Cow", "Buffalo", "Goat", "Sheep"])

    symptoms = st.multiselect(
        "Select Symptoms",
        ["Fever", "Not Eating", "Low Milk Production",
         "Swelling", "Coughing", "Skin Lesions",
         "Limping", "Diarrhea"]
    )

    if st.button("Analyze Symptoms"):

        prompt = f"""
        Animal: {animal}
        Symptoms: {', '.join(symptoms)}

        Provide:
        1. Possible disease
        2. Urgency level (Low/Medium/High)
        3. First aid advice
        """

        response = openai.ChatCompletion.create(
            model="gpt-4",
            messages=[{"role": "user", "content": prompt}]
        )

        result = response.choices[0].message.content
        st.success(result)

# ==============================
# 2️⃣ IMAGE ANALYSIS
# ==============================
elif menu == "Image Analysis":

    st.header("📸 Upload Animal Image for Analysis")

    uploaded_file = st.file_uploader("Upload image", type=["jpg", "png"])

    if uploaded_file:

        image = Image.open(uploaded_file)
        st.image(image, caption="Uploaded Image", use_column_width=True)

        if st.button("Analyze Image"):

            buffered = uploaded_file.getvalue()
            base64_image = base64.b64encode(buffered).decode()

            prompt = "Analyze this animal image and identify possible health issues and suggest treatment."

            response = openai.ChatCompletion.create(
                model="gpt-4-vision-preview",
                messages=[
                    {"role": "user", "content": [
                        {"type": "text", "text": prompt},
                        {"type": "image_url", "image_url": f"data:image/jpeg;base64,{base64_image}"}
                    ]}
                ],
                max_tokens=500
            )

            st.success(response.choices[0].message.content)

# ==============================
# 3️⃣ MILK TRACKER
# ==============================
elif menu == "Milk Tracker":

    st.header("🥛 Milk Production Tracker")

    animal = st.selectbox("Select Animal", ["Cow", "Buffalo"])

    milk = st.number_input("Enter today's milk production (liters)", min_value=0.0)

    if st.button("Save Record"):
        today = datetime.now().strftime("%Y-%m-%d")
        cursor.execute(
            "INSERT INTO milk_records (animal, date, milk) VALUES (?, ?, ?)",
            (animal, today, milk)
        )
        conn.commit()
        st.success("Record saved!")

    df = pd.read_sql_query(
        f"SELECT * FROM milk_records WHERE animal='{animal}'",
        conn
    )

    if not df.empty:
        st.line_chart(df["milk"])

        if len(df) > 3:
            last = df["milk"].iloc[-1]
            avg = df["milk"].mean()
            if last < avg * 0.7:
                st.error("⚠️ Sudden drop detected! Check animal health.")

# ==============================
# 4️⃣ VACCINATION REMINDER
# ==============================
elif menu == "Vaccination Reminder":

    st.header("💉 Vaccination Schedule")

    animal = st.selectbox("Select Animal Type", ["Cow", "Buffalo", "Goat", "Sheep"])

    age = st.number_input("Enter Age (in months)", min_value=0)

    if st.button("Generate Schedule"):

        prompt = f"""
        Animal: {animal}
        Age: {age} months

        Provide vaccination schedule and deworming guidance.
        """

        response = openai.ChatCompletion.create(
            model="gpt-4",
            messages=[{"role": "user", "content": prompt}]
        )

        st.success(response.choices[0].message.content)