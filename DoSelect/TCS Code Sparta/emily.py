import httplib, urllib, base64, json

headers = {
    # Request headers. Replace the placeholder key below with your subscription key.
    'Content-Type': 'application/json',
    'Ocp-Apim-Subscription-Key': '807b634f9448436e83a84656a2f62624',
}

params = urllib.urlencode({
})

n = int(raw_input())
for i in range(n) :
	url_image = str(raw_input())
	body = "{ 'url': \'"+url_image+"\' }"

	try:
	    conn = httplib.HTTPSConnection('westus.api.cognitive.microsoft.com')
	    conn.request("POST", "/emotion/v1.0/recognize?%s" % params, body, headers)
	    response = conn.getresponse()
	    data = response.read()
	    use_data = json.loads(data)

	    max_emotion = 0.0000
	    answer = ''

	    if use_data[0]['scores']['anger'] > max_emotion :
	    	max_emotion = use_data[0]['scores']['anger']
	    	answer = 'anger'

	    if use_data[0]['scores']['contempt'] > max_emotion :
	    	max_emotion = use_data[0]['scores']['contempt']
	    	answer = 'contempt'

	    if use_data[0]['scores']['disgust'] > max_emotion :
	    	max_emotion = use_data[0]['scores']['disgust']
	    	answer = 'disgust'

	    if use_data[0]['scores']['fear'] > max_emotion :
	    	max_emotion = use_data[0]['scores']['fear']
	    	answer = 'fear'

	    if use_data[0]['scores']['happiness'] > max_emotion :
	    	max_emotion = use_data[0]['scores']['happiness']
	    	answer = 'happiness'

	    if use_data[0]['scores']['neutral'] > max_emotion :
	    	max_emotion = use_data[0]['scores']['neutral']
	    	answer = 'neutral'

	    if use_data[0]['scores']['sadness'] > max_emotion :
	    	max_emotion = use_data[0]['scores']['sadness']
	    	answer = 'sadness'

	    if use_data[0]['scores']['surprise'] > max_emotion :
	    	max_emotion = use_data[0]['scores']['surprise']
	    	answer = 'surprise'
	    print(answer)
	    conn.close()
	except Exception as e:
	    print("[Errno {0}] {1}".format(e.errno, e.strerror))