import pandas as pd
from pandas import DataFrame


prediction_file = pd.read_csv("gcPredictionFile.csv")
# print(prediction_file.shape)

col1 = DataFrame([i+1 for i in range(prediction_file.shape[0])])
col2 = DataFrame([2.77 for i in range(prediction_file.shape[0])])
col3 = DataFrame(["TRUE" for i in range(prediction_file.shape[0])])

# print(col1.shape)

result = pd.concat([col1, col2, col3], axis=1)

# print(result.shape)

result.to_csv("prediction.csv", header=["serialNum", "initialFreeMemory", "gcRun"], index=None)