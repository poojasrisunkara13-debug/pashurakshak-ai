import streamlit as st
import sqlite3
import pandas as pd
import matplotlib.pyplot as plt
from PIL import Image
import datetime

st.set_page_config(page_title="PashuRakshak AI", layout="wide")

st.title("🐄 PashuRakshak AI - Livestock Health Assistant")
st.markdown("Smart AI-based livestock monitoring system")

# Database setup
conn = sqlite3.connect("livestock.db", check_same_thread=False)
cursor = conn.cursor()

cursor.execute("""
CREATE TABLE IF NOT EXISTS milk_data (
    date TEXT,
    animal TEXT,
    milk REAL
)
""")
conn.commit()

menu = st.sidebar.selectbox("Navigation", [
    "Disease Prediction",
    "Image Analysis",
    "Milk Tracker",
    "Vaccination Reminder"
])

animal = st.sidebar.selectbox("Select Animal", ["Cow", "Buffalo", "Goat", "Sheep dog", "Pig"])

# ---------------------------
# Disease Prediction (Rule Based AI)
# ---------------------------
if menu == "Disease Prediction":

    st.header("🩺 Symptom-Based Disease Prediction")

    symptoms = st.multiselect(
        "Select Symptoms",
        ["Fever", "Not Eating", "Low Milk Production",
         "Swelling", "Coughing", "Skin Lesions",
         "Limping", "Diarrhea"]
    )

    if st.button("Analyze Symptoms"):

        if "Fever" in symptoms and "Not Eating" in symptoms:
            st.error("Possible Disease: Infection\nUrgency: HIGH\nAdvice: Consult veterinarian immediately.")
        elif "Low Milk Production" in symptoms:
            st.warning("Possible Issue: Stress or Nutritional Deficiency\nUrgency: Medium\nAdvice: Improve feed quality.")
        elif "Skin Lesions" in symptoms:
            st.warning("Possible Disease: Skin Infection\nAdvice: Clean area and apply antiseptic.")
        else:
            st.success("No major risk detected. Monitor animal condition.")

# ---------------------------
# Image Analysis (Demo Version)
# ---------------------------
elif menu == "Image Analysis":

    st.header("📸 Upload Animal Image")

    uploaded_file = st.file_uploader("Upload image", type=["jpg", "png"])

    if uploaded_file:
        image = Image.open(uploaded_file)
        st.image(image, caption="Uploaded Image", use_column_width=True)

        if st.button("Analyze Image"):
            st.success("AI Analysis: Possible minor skin irritation detected. Clean area and monitor.")

# ---------------------------
# Milk Tracker
# ---------------------------
elif menu == "Milk Tracker":

    st.header("🥛 Milk Production Tracker")

    milk_amount = st.number_input("Enter today's milk production (liters)", min_value=0.0)

    if st.button("Save Data"):
        today = datetime.date.today().isoformat()
        cursor.execute("INSERT INTO milk_data VALUES (?, ?, ?)", (today, animal, milk_amount))
        conn.commit()
        st.success("Data Saved!")

    df = pd.read_sql_query("SELECT * FROM milk_data WHERE animal=?", conn, params=(animal,))

    if not df.empty:
        df["date"] = pd.to_datetime(df["date"])
        st.line_chart(df.set_index("date")["milk"])

        if len(df) > 1 and df["milk"].iloc[-1] < df["milk"].mean() * 0.7:
            st.error("⚠️ Abnormal milk drop detected!")

# ---------------------------
# Vaccination Reminder
# ---------------------------
elif menu == "Vaccination Reminder":

    st.header("💉 Vaccination Schedule")

    age = st.number_input("Enter animal age (months)", min_value=0)

    if st.button("Generate Schedule"):
        if age < 6:
            st.success("Recommended: FMD vaccine at 4 months. Deworming every 3 months.")
        elif age < 12:
            st.success("Recommended: Booster vaccination. Regular health checkups.")
        else:
            st.success("Annual vaccination recommended.")