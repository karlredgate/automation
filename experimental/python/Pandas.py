
# https://pandas.pydata.org/pandas-docs/stable/tutorials.html
# https://pandas.pydata.org/pandas-docs/stable/10min.html#min
# https://www.dataquest.io/blog/pandas-python-tutorial/

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

s = pd.Series([1,3,5,np.nan,6,8])

dates = pd.date_range('20130101', periods=6)

