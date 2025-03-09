# **Parallel Processing: Counting and Separating Even & Odd Numbers**

## **Project Overview**
This project demonstrates the use of **OpenMP** to parallelize the task of counting and separating even and odd numbers from an array of random integers. It compares the **sequential** and **parallel** execution times to evaluate the performance benefits of parallelization.

## **Features**
- Generates an array with **at least 1000 random integers**.
- Separates **even** and **odd** numbers into two new arrays.
- Supports **both sequential and parallel execution**.
- Allows the user to specify the number of threads for parallel execution.
- Compares execution time between **sequential** and **parallel** implementations.
- Execution times are analyzed using **Excel charts**.

## **Technologies Used**
- **C (GCC Compiler)**
- **OpenMP** for parallel execution
- **Git & GitHub** for version control
- **Excel** for performance comparison charts

---

## **Installation & Setup**
### **1. Clone the Repository**
```sh
git clone https://github.com/Abdul-Ahad-503/PDC_Assignment_1.git
cd PDC_Assignment_1
```


#### **Parallel Version:**
```sh
gcc -fopenmp Assignment1.c -o Assignment1 -O2
```



#### **Run Parallel Version (with N threads):**
```sh
./Assignment1 <num_threads>
```
Example:
```sh
./parallel 8
```

---


## **Results & Conclusion**
- **Parallel execution significantly improves performance** for large arrays.
- **Increasing threads reduces execution time**, but beyond a certain point, overhead limits speedup.
- **OpenMP efficiently parallelizes loop-based operations**, making it useful for computational tasks involving large datasets.

---

## **Author**
**Abdul Ahad**  
📂 [GitHub Repository](https://github.com/Abdul-Ahad-503/PDC_Assignment_1)

Feel free to contribute, suggest improvements, or report issues!

---
