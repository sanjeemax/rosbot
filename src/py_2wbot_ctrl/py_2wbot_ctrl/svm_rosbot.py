import numpy as np
import matplotlib.pyplot as plt
from sklearn.svm import SVR
import glob
import os
import pickle
import pandas as pd



CSV_DIR_PATH = '/home/lasantha/matlab/pilco-matlab/scenarios/rosbot'
PCKL_FILE = 'svm_poly_model.pkl'
class SVM_rosbot:
    def __init__(self):

        self.svr_d = {"linear": SVR(kernel='linear', C=100, gamma= "auto"),"poly": SVR(kernel="poly", C=100, gamma="auto", degree=3, epsilon=0.1, coef0=1),
                      "rbf": SVR(kernel="rbf", C=100, gamma= 0.1, epsilon=0.1)}

        self.csv_files = None
        self.type = "rbf"
        self.X_train = np.zeros((0,))
        self.Y_train = np.zeros((0,))
        print("SVM_rosbot initialization")


    def loadModel(self,type="poly"):
        with open(CSV_DIR_PATH + PCKL_FILE, 'rb') as f:
            self.svr_d[type] = pickle.load(f)
    def setupSVM(self, type="poly"):
        self.type = type
        self.csv_files = list(glob.glob(os.path.join(CSV_DIR_PATH, '*.csv')))
        self.loadData()
        self.svr_d[type].fit(self.X_train,self.Y_train)
        # Export the trained model using pickle
        with open(CSV_DIR_PATH + PCKL_FILE, 'wb') as f:
            pickle.dump(self.svr_d[type], f)
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
        self.Y_train = np.squeeze(self.Y_train)
        print(np.shape(self.X_train))
        print(np.shape(self.Y_train))

    def predict(self, new_X):
        # Predict the target values for the new data
        y_pred = self.svr_d[self.type].predict(new_X)

        #print("Predicted y:")
        #print(y_pred)
        return y_pred

def display_menu():
    print("Menu:")
    print("1. Train SVM on Data")
    print("2. Load model back")
    print("3. predict new Data")
    print("4. Exit")

def main(args=None):
    print("SVM regression")
    rosbot_svm = SVM_rosbot()
    while True:
        display_menu()
        choice = input("Enter your choice: ")

        if choice == '1':
            rosbot_svm.setupSVM("poly")
        elif choice == '2':
            rosbot_svm.loadModel()
        elif choice == '3':
            X = np.array([2.44, 2.7, -0.0, 0.69, 0.0, -0.0])
            X_new_single_reshaped = X.reshape(1, -1)

            # Predict the target value for the single data point
            y_pred = rosbot_svm.predict(X_new_single_reshaped)
            print(np.shape(y_pred))
            print(y_pred)
        elif choice == '4':
            print("Exiting...")
            break
        else:
            print("Invalid choice. Please enter a valid option.")

if __name__ == '__main__':
    main()
