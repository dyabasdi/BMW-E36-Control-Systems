from sklearn.linear_model import LinearRegression
import numpy as np

# def celsius_to_fahrenheit(val):
#     return (val * (9/5)) + 32

# # from bosch sensor data sheet
# resistances = np.array([[100.0], [107.7], [115.4], [123.1], [130.8], [138.5], [146.2]])

# temps_in_C = np.array([0.0, 20.0, 40.0, 60.0, 80.0, 100.0, 120.0])

# temps_in_F = [celsius_to_fahrenheit(val) for val in temps_in_C]

# linear_relationship = LinearRegression().fit(resistances, temps_in_F)

# slope = linear_relationship.coef_
# intercept = linear_relationship.intercept_
# print("Linear relationship for Bosch Temp Sensor in °F")
# print("Slope: ", slope)
# print("Intercept:", intercept)

# temp_in_F_at_120 = (slope*120) + intercept

# # test calculation
# print("Temperature at 120 ohms: ", temp_in_F_at_120)

# X = np.linspace(170, 190, 255).reshape(-1, 1)
# y = np.linspace(0, 255, 255).reshape(-1, 1)


# linear_relationship = LinearRegression().fit(X, y)

# slope = linear_relationship.coef_
# intercept = linear_relationship.intercept_
# print("Linear relationship for Bosch Temp Sensor in °F")
# print("Slope: ", slope)
# print("Intercept:", intercept)

# duty_cycle_at_175 = ((slope*175) + intercept)*(100/255)

# # test calculation
# print("Duty Cycle at 175°F: ", duty_cycle_at_175)

X = np.linspace(170, 190, 255).reshape(-1, 1)
y = np.linspace(0, 255, 255).reshape(-1, 1)


linear_relationship = LinearRegression().fit(X, y)

slope = linear_relationship.coef_
intercept = linear_relationship.intercept_
print("Linear relationship for Bosch Temp Sensor in °F")
print("Slope: ", slope)
print("Intercept:", intercept)

duty_cycle_at_175 = ((slope*175) + intercept)*(100/255)

# test calculation
print("Duty Cycle at 175°F: ", duty_cycle_at_175)