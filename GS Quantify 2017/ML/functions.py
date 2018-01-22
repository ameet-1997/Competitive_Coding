import pandas as pd
from pandas import DataFrame
import matplotlib.pyplot as plt


def get_token_values():
	# Load the train data as a DataFrame
	train_data = pd.read_csv("gcTrainingSet.csv")
	# print(train_data.dtypes)


	# Store the Memory usage per token
	# The value is almost a constant
	tokens_temp = {}
	tokens = {}

	# 91 different tokens exist
	for i in range(91):
		tokens_temp["token_"+str(i+1)] = []

	# Get the memory usage values from the training data
	for i in range(train_data.shape[0]):
		if not train_data.iloc[i,3]:
			tokens_temp[train_data.iloc[i,2]].append(train_data.iloc[i,1] - train_data.iloc[i,-1])

	# Get the average of all the values collected
	for key in tokens_temp:
		tokens[key] = sum(tokens_temp[key])/len(tokens_temp[key])

	# print(tokens_temp["token_34"])
	# print(tokens_temp["token_45"])

	df = DataFrame.from_dict(tokens, orient='index')
	df.to_csv("token_values.csv", header=None)

	return tokens

def plot_after_garbage():
	train_data = pd.read_csv("gcTrainingSet.csv")

	y_values = []
	x_values = []
	counter = 0

	for i in range(train_data.shape[0]):
		if train_data.iloc[i,3]:
			y_values.append(train_data.iloc[i,4])
			x_values.append(counter)
			counter+=1

	plt.plot(x_values, y_values)
	plt.show()
