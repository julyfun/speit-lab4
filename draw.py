import pandas as pd
import matplotlib.pyplot as plt
df = pd.read_csv("res.csv")
FUNC_NAMES = ["void bubble_sort(int arr[], int len)",
              "void insertion_sort(int arr[], int len)",
              "void selection_sort(int arr[], int len)",
              "void merge_sort_api(int arr[], int len)",
              "void quick_sort_api(int arr[], int len)"]
for idx, row in df.head(5).iterrows():
    plt.plot(row.index, row.values, label=f"{FUNC_NAMES[idx]}")
# 添加一个图
plt.legend()
plt.xlabel('Dimension')
plt.ylabel('Time(s)')

plt.show()

