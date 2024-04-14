import glob
import os
import pickle

import pandas as pd
import matplotlib as plot
from sklearn.metrics import r2_score
from sklearn.gaussian_process import GaussianProcessRegressor
from sklearn.gaussian_process.kernels import RBF, ConstantKernel, WhiteKernel
import numpy as np
#import GPy


CSV_DIR_PATH = '/home/lasantha/matlab/pilco-matlab/scenarios/rosbot'
class GPR_rosbot:
    def __init__(self):
        self.kernel = ConstantKernel(1.0) + ConstantKernel(1.0) * RBF(10)  + WhiteKernel(5)
        self.model = GaussianProcessRegressor(kernel=self.kernel)
        # Define kernel function (e.g., Radial Basis Function kernel)
        #self.model = None
        #self.kernel = None
        self.csv_files = None
        self.X_train = np.zeros((0,))
        self.Y_train = np.zeros((0,))
        print("GPR_rosbot initialization")

    def loadModel(self):
        with open(CSV_DIR_PATH + 'gp_model.pkl', 'rb') as f:
            self.model = pickle.load(f)
    def setupGPR(self):
        self.csv_files = list(glob.glob(os.path.join(CSV_DIR_PATH, '*.csv')))
        self.model.fit(self.X_train,self.Y_train)
        # Export the trained model using pickle
        with open(CSV_DIR_PATH + 'gp_model.pkl', 'wb') as f:
            pickle.dump(self.model, f)
    def loadData(self):
        listx = []
        listy = []
        arr = np.array([])
        for csv_file in self.csv_files:
            print(csv_file)
            df = pd.read_csv(csv_file, na_filter=True)
            selected_x = df.iloc[:, [7, 8, 11, 13, 14, 18]]
            selected_y = df.iloc[:, [6]]
            listx.append(selected_x)
            listy.append(selected_y)
            print(np.shape(arr))
        self.X_train = np.vstack(listx)
        self.Y_train = np.vstack(listy)
        print(np.shape(self.X_train))
        print(np.shape(self.Y_train))

    def predict(self, new_X):
        # Predict the target values for the new data
        y_pred = self.model.predict(new_X)

        print("Predicted y:")
        print(y_pred)
        return y_pred

def display_menu():
    print("Menu:")
    print("1. Train GP on Data")
    print("2. Load model back")
    print("3. predict new Data")
    print("4. Exit")

def main(args=None):
    print("gaussian process regression")
    rosbot_gpr = GPR_rosbot()
    while True:
        display_menu()
        choice = input("Enter your choice: ")

        if choice == '1':
            rosbot_gpr.loadData()
            rosbot_gpr.setupGPR()
        elif choice == '2':
            rosbot_gpr.loadModel()
        elif choice == '3':
            X = np.array([2.44, 2.7, -0.0, 0.69, 0.0, -0.0])
            X_new_single_reshaped = X.reshape(1, -1)

            # Predict the target value for the single data point
            y_pred = rosbot_gpr.model.predict(X_new_single_reshaped)

            print(y_pred)
        elif choice == '4':
            print("Exiting...")
            break
        else:
            print("Invalid choice. Please enter a valid option.")

if __name__ == '__main__':
    main()
