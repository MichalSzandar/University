import pandas as pd
import matplotlib.pyplot as plt

# 1) Load your data (if comma-separated, change sep=r'\s+' to sep=',')
df_select = pd.read_csv('./select/select_test.csv', sep=r'\s+')
df_random = pd.read_csv('./randomselect/randomselect_test.csv', sep=r'\s+')

# 2) Compute average metrics per (n, k)
avg_select = (
    df_select
    .groupby(['n', 'k'])
    .agg({'key_comparisons': 'mean', 'key_swaps': 'mean'})
    .reset_index()
)
avg_random = (
    df_random
    .groupby(['n', 'k'])
    .agg({'key_comparisons': 'mean', 'key_swaps': 'mean'})
    .reset_index()
)

# Helper to draw one metric for one algorithm
def plot_metric(df, algo_name, metric):
    plt.figure()
    for k_val in sorted(df['k'].unique()):
        subset = df[df['k'] == k_val]
        plt.plot(subset['n'], subset[metric], label=f'k={k_val}')
    plt.xlabel('Input size n')
    plt.ylabel(metric.replace('_', ' ').title())
    plt.title(f'{algo_name.capitalize()} – {metric.replace("_", " ").title()} vs n')
    plt.legend()
    plt.tight_layout()

    filename = f'./charts/select/{algo_name}_{metric}.png'
    plt.savefig(filename)

    plt.show()

# 3) Four separate plots:
plot_metric(avg_select,    'select',       'key_comparisons')
plot_metric(avg_select,    'select',       'key_swaps')
plot_metric(avg_random,    'randomselect', 'key_comparisons')
plot_metric(avg_random,    'randomselect', 'key_swaps')
