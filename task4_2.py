# Importing necessary libraries
import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

# Loading the dataset from the CSV file
dataset = pd.read_csv('D:\Projects&Assinment\MIA Training\Task 4\Task 4.2\shrink_ray_dataset.csv')

# Extracting the 'Power' and 'Shrinkage' columns
power = dataset['Power']
shrinkage = dataset['Shrinkage']

# Calculating the average shrinkage
average_shrinkage = sum(shrinkage) / len(shrinkage)

# Displaying the average shrinkage
print("Average Shrinkage:", average_shrinkage)

# Finding the maximum power and corresponding shrinkage
max_power_index = power.idxmax()
max_power = power[max_power_index]
max_power_shrinkage = shrinkage[max_power_index]

# Displaying the maximum power and corresponding shrinkage
print("Max Power:", max_power)
print("Corresponding Shrinkage:", max_power_shrinkage)

# Finding the minimum power and corresponding shrinkage
min_power_index = power.idxmin()
min_power = power[min_power_index]
min_power_shrinkage = shrinkage[min_power_index]

# Displaying the minimum power and corresponding shrinkage
print("Min Power:", min_power)
print("Corresponding Shrinkage:", min_power_shrinkage)

# Plot the data points
plt.scatter(power, shrinkage, label='Data Points')

# Fit a linear model using numpy's polyfit function
model = np.polyfit(power, shrinkage, deg=1)
predicted_shrinkage = np.polyval(model, power)

# Plot the linear model
plt.plot(power, predicted_shrinkage, color='red', label='Linear Model')

# Set the labels and title for the plot
plt.xlabel('Power')
plt.ylabel('Shrinkage')
plt.title('Linear Model of Power vs Shrinkage')

# Show the legend
plt.legend()

# Display the plot
plt.show()