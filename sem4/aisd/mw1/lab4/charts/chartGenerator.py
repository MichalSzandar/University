import pandas as pd
import matplotlib.pyplot as plt

# Ścieżka do pliku z wynikami
csv_path = "results/BST/BST_results.csv"

# Wczytanie danych
df = pd.read_csv(csv_path)

# Grupowanie po 'n' i obliczanie średnich oraz maksymalnych wartości
agg = df.groupby("n").agg({
    "key_comparisons": ["mean", "max"],
    "pointer_ops": ["mean", "max"],
    "current_height": ["mean", "max"]
})

# Spłaszczenie wielopoziomowych nazw kolumn
agg.columns = ['_'.join(col) for col in agg.columns]
agg = agg.reset_index()

# Wykres 1: Liczba porównań kluczy
plt.figure(figsize=(10, 6))
plt.plot(agg['n'], agg['key_comparisons_mean'], marker='o', label='Średnia')
plt.plot(agg['n'], agg['key_comparisons_max'], marker='x', label='Maksymalna')
plt.title('Liczba porównań kluczy na operację')
plt.xlabel('n')
plt.ylabel('Liczba porównań')
plt.grid(True)
plt.legend()
plt.tight_layout()
plt.savefig("results/BST/key_comparisons_plot.png")
plt.show()

# Wykres 2: Operacje na wskaźnikach
plt.figure(figsize=(10, 6))
plt.plot(agg['n'], agg['pointer_ops_mean'], marker='o', label='Średnia')
plt.plot(agg['n'], agg['pointer_ops_max'], marker='x', label='Maksymalna')
plt.title('Liczba operacji na wskaźnikach na operację')
plt.xlabel('n')
plt.ylabel('Liczba operacji')
plt.grid(True)
plt.legend()
plt.tight_layout()
plt.savefig("results/BST/pointer_ops_plot.png")
plt.show()

# Wykres 3: Wysokość drzewa
plt.figure(figsize=(10, 6))
plt.plot(agg['n'], agg['current_height_mean'], marker='o', label='Średnia')
plt.plot(agg['n'], agg['current_height_max'], marker='x', label='Maksymalna')
plt.title('Wysokość drzewa po operacjach')
plt.xlabel('n')
plt.ylabel('Wysokość')
plt.grid(True)
plt.legend()
plt.tight_layout()
plt.savefig("results/BST/tree_height_plot.png")
plt.show()
