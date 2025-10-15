import matplotlib.pyplot as plt

path = "errors.csv"

x_vals = []
c_vals = []
q_vals = []

with open(path, "r") as file:
    for line in file:
        row = line.strip().split(',')
        if len(row) != 3:
            continue
        try:
            x = float(row[0])
            c_err = float(row[1])
            q_err = float(row[2])
        except ValueError:
            continue  # skip header/bad rows
        if x > 100000:
            x_vals.append(x)
            c_vals.append(c_err)
            q_vals.append(q_err)

# Create the plot
plt.figure(figsize=(8, 5))
plt.scatter(x_vals, c_vals, s=8, label="1/sqrtf(x)", alpha=0.7)
plt.scatter(x_vals, q_vals, s=8, label="Quake III rsqrt", alpha=0.7)

#plt.xscale("log")
plt.yscale("log")

plt.xlabel("x (input value)")
plt.ylabel("Relative Error |f - d| / |d|")
plt.title("Comparison of Inverse Square Root Accuracy")
plt.legend()
plt.grid(True, which="both", linestyle="--", alpha=0.5)
plt.tight_layout()

# Save plot to same folder as CSV
save_path = "data/dat_plot.png"
plt.savefig(save_path, dpi=300)
print(f"Plot saved to: {save_path}")

plt.show()
