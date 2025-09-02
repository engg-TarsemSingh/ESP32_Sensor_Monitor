import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt

Sensor_data = []
rate_data = []
First = True
count = 0

def update():
    global Sensor_data
    global First

    center_value = 1915
    difference = 15
    y_upper = center_value+difference
    y_lower = center_value-difference

    plt.figure()
    plt.plot(Sensor_data, label='Sensor Data')
    plt.axhline(center_value,color='red',linestyle="--")
    #plt.ylim(y_lower,y_upper)
    plt.xlabel('Time')
    plt.ylabel('Sensor Value')
    plt.title('Sensor Data Over Time')
    plt.legend()
    
    path = r"graph.png"
    if First :
        plt.figure()
        plt.savefig(path)
        First = False
    plt.savefig(path)
    plt.close()


def ploting(input):
    global Sensor_data
    global count
    Sensor_data.append(input)
    Sensor_data = Sensor_data[-60:]
    count=count+1
    if(count==1):
        update()
        count = 0