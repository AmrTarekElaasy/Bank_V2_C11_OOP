# 💰 Bank_V2_C11_OOP - Bank Management System in C++

A fully integrated banking system developed in C++ using Object-Oriented Programming (OOP), containing all core functionalities for managing customers, managers, financial operations, and currency exchange.

---

## 🔐 Login Credentials

- **Main Administrator:**
  - Username: `Admin`
  - Password: `Admin`

> ⚠️ If the password is entered incorrectly 3 consecutive times, the system will shut down automatically.

---

## 🌟 System Features

### ✅ Customer Management
- View customer list  
- Add new customer  
- Delete customer  
- Update customer data  
- Search for a customer  

### 💰 Financial Operations
- Deposit funds  
- Withdraw funds  
- Transfer funds between accounts  

### 👥 Manager Management
- View manager list  
- Add new manager  
- Delete manager  
- Update manager data (including editing permissions)  
- Search for a manager  

### 💱 Currency Exchange
- View available currencies  
- Search for a specific currency  
- Update exchange rates  
- Currency calculator between any two currencies  

### 🧾 Log Management
- **Transfer Log:** Each transfer operation is saved in an encrypted file  
- **Login Log:** All login attempts (successful or failed) are saved in an encrypted file  
- **Error Log:** All system errors are saved in `ErrorFile.log`  
- **Dedicated Screens** to view:
  - Transfer history  
  - Login history  

---

## 🔒 Security System

- Customer data is encrypted  
- Manager data is encrypted in the `Users` file  
- All logs (transfers, login, errors) are stored in **encrypted** files  
- No manager can view or edit the main administrator's data  
- Permission-based system to control manager access  
- Decryption is handled temporarily inside the system UI only  

---

## 📋 System Constraints

- The main administrator cannot be deleted  
- The main administrator’s data can only be edited by themselves  
- Managers cannot log in without active permission  

---

## 📄 License

This project is licensed under the [MIT License](LICENSE)

---
[![Download](https://img.shields.io/badge/Download%20BankSystem--V2.zip-blue?style=for-the-badge&logo=github)](https://github.com/AmrTarekElaasy/Bank_V2_C11_OOP/raw/master/BankSystem_V2.zip)

---


<div align="center">
  <p>Developed by <a href="https://github.com/AmrTarekElaasy">Amr Tarek Elaasy</a></p>
  <p>💻 Bank System Version 2 - C++ OOP Project 💻</p>
</div>
