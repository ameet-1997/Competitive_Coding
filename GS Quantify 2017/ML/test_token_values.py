import pandas as pd
from pandas import DataFrame
from functions import get_token_values, plot_after_garbage

# Load the training data
train_data = pd.read_csv("gcTrainingSet.csv")

# Dictionary containing memory usage per token
tokens = get_token_values()

# Plot memory usage after garbage collection
# plot_after_garbage()


# print(4.66- tokens["token_23"])
# print(4.8- tokens["token_45"])

# for i in range(train_data.shape[0]):
# 	if train_data.iloc[i,3]:
# 		print(str(train_data.iloc[i,1])+ ", " + str(train_data.iloc[i,1] - tokens[train_data.iloc[i,2]]) + "," + str(i+1))

