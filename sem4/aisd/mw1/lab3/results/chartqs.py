
import os

import pandas as pd
import matplotlib.pyplot as plt

# ----- Hard‑coded file paths and output directory -----
QS_FILE = 'quick_sort/qs_test.csv'
DP_FILE = 'dual_pivot_qs/dual_pivot_qs_test.csv'
OUTDIR = 'charts/sorting'

def load_and_aggregate(filename: str) -> pd.DataFrame:
    df = pd.read_csv(filename, sep=r"\s+", header=0)
    df.columns = ['n', 'key_swaps', 'key_comparisons']
    return df.groupby('n', as_index=False).mean()


def plot_metric(ax, x, y1, y2, label1, label2, xlabel, ylabel, title):
    ax.plot(x, y1, marker='o', label=label1)
    ax.plot(x, y2, marker='o', label=label2)
    ax.set_xlabel(xlabel)
    ax.set_ylabel(ylabel)
    ax.set_title(title)
    ax.legend()
    ax.grid(True)


def main():
    # Load and aggregate data
    qs_data = load_and_aggregate(QS_FILE)
    dp_data = load_and_aggregate(DP_FILE)

    # Ensure output directory exists
    os.makedirs(OUTDIR, exist_ok=True)

    # Plot average key swaps vs n
    fig, ax = plt.subplots()
    plot_metric(
        ax,
        qs_data['n'],
        qs_data['key_swaps'],
        dp_data['key_swaps'],
        'Quicksort',
        'Dual Pivot Quicksort',
        'Array size n',
        'Average key swaps',
        'Average Key Swaps vs n'
    )
    swaps_path = os.path.join(OUTDIR, 'swaps_vs_n.png')
    fig.savefig(swaps_path)
    print(f"Saved plot of key swaps to {swaps_path}")

    # Plot average key comparisons vs n
    fig, ax = plt.subplots()
    plot_metric(
        ax,
        qs_data['n'],
        qs_data['key_comparisons'],
        dp_data['key_comparisons'],
        'Quicksort',
        'Dual Pivot Quicksort',
        'Array size n',
        'Average key comparisons',
        'Average Key Comparisons vs n'
    )
    comps_path = os.path.join(OUTDIR, 'comparisons_vs_n.png')
    fig.savefig(comps_path)
    print(f"Saved plot of key comparisons to {comps_path}")

    # Show plots interactively
    plt.show()


if __name__ == '__main__':
    main()