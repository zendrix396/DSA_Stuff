def calculate_emi(principal, annual_rate, years):
    # Convert annual rate to monthly
    monthly_rate = annual_rate / (12 * 100)
    
    # Convert years to months
    tenure_months = years * 12
    
    # EMI calculation
    emi = principal * monthly_rate * (1 + monthly_rate)**tenure_months
    emi = emi / ((1 + monthly_rate)**tenure_months - 1)
    
    return emi

# Input values
principal = 420000
annual_rate = 8.5
years = 20

emi = calculate_emi(principal, annual_rate, years)
print(f"Calculated EMI: ₹{emi:.2f}")

# Calculate total payment
total_payment = emi * years * 12
interest_paid = total_payment - principal
print(f"\nLoan Analysis:")
print(f"Principal Amount: ₹{principal:,.2f}")
print(f"Total Payment: ₹{total_payment:,.2f}")
print(f"Total Interest: ₹{interest_paid:,.2f}")