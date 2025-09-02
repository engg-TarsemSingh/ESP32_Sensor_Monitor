from flask import request,jsonify,Flask
from Code import ploting #,rateplot
import threading

app = Flask(__name__)

@app.route("/pulse",methods=["POST"])
def Esp_sent():
    global data_recived
    voltage = request.json.get("Sensor-Data")
    thread1 = threading.Thread(target=ploting,args=(float(voltage),)).start()

    return jsonify({"status": f"SUCCESSFULLY RCEIVED {voltage}"})

    
if __name__ == '__main__' :
    app.run("0.0.0.0",port=5000)