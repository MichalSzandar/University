import pandas as pd
import matplotlib.pyplot as plt

# 1) Load your data (if comma-separated, change sep=r'\s+' to sep=',')
df_bs = pd.read_csv('./binarysearch/bs_experimental_test.csv', sep=r'\s+')

# 2) Compute average metrics per (n)
avg_bs = (
    df_bs
    .groupby(['n'])
    .agg({'key_comparisons': 'mean', 'execution_time': 'mean'})
    .reset_index()
)

# Helper to draw one metric for one algorithm
def plot_metric(df, algo_name, metric):
    plt.figure()
    plt.plot(df['n'], df[metric], label=f'{metric.replace("_", " ").title()}')
    plt.xlabel('Input size n')
    plt.ylabel(metric.replace('_', ' ').title())
    plt.title(f'{algo_name.capitalize()} – {metric.replace("_", " ").title()} vs n')
    plt.legend()
    plt.tight_layout()
    
    filename = f'./charts/binary_search/{algo_name}_{metric}_random.png'
    plt.savefig(filename)

    plt.show()

# 3) Four separate plots:
plot_metric(avg_bs,    'binary_search',       'key_comparisons')
plot_metric(avg_bs,    'binary_search',       'execution_time')
