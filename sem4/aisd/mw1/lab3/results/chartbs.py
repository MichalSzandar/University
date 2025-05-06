import pandas as pd
import matplotlib.pyplot as plt

# 1) Load your data (if comma-separated, change sep=r'\s+' to sep=',')
df_bs = pd.read_csv('./binarysearch/bs_test.csv', sep=r'\s+')

# 2) Compute average metrics per (n, v)
avg_bs = (
    df_bs
    .groupby(['n', 'v'])
    .agg({'key_comparisons': 'mean', 'execution_time': 'mean'})
    .reset_index()
)

# Helper to draw one metric for one algorithm
def plot_metric(df, algo_name, metric):
    plt.figure()
    for v_val in sorted(df['v'].unique()):
        subset = df[df['v'] == v_val]
        if v_val == 0:
            plt.plot(subset['n'], subset[metric], label=f'close to beginning')
        elif v_val == 1:
            plt.plot(subset['n'], subset[metric], label=f'close to middle')
        elif v_val == 2:
            plt.plot(subset['n'], subset[metric], label=f'close to end')
        elif v_val == 3:
            plt.plot(subset['n'], subset[metric], label=f'out of bounds')
    plt.xlabel('Input size n')
    plt.ylabel(metric.replace('_', ' ').title())
    plt.title(f'{algo_name.capitalize()} – {metric.replace("_", " ").title()} vs n')
    plt.legend()
    plt.tight_layout()

    filename = f'./charts/binary_search/{algo_name}_{metric}.png'
    plt.savefig(filename)
    plt.show()

# 3) Four separate plots:
plot_metric(avg_bs,    'binary_search',       'key_comparisons')
plot_metric(avg_bs,    'binary_search',       'execution_time')
