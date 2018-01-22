import urllib2, json, httplib, urllib, base64
#import urllib.request


date1 = str(raw_input())
date2 = str(raw_input())
min_diameter = float(raw_input())
max_diameter = float(raw_input())

#final_url = "https://api.nasa.gov/neo/rest/v1/feed?start_date="+date1+"&end_date="+date2+"&api_key=DEMO_KEY"
final_url = "/neo/rest/v1/feed?start_date="+date1+"&end_date="+date2+"&api_key=DEMO_KEY"
"""response = urllib2.urlopen(final_url)"""
conn = httplib.HTTPSConnection("api.nasa.gov")
conn.request("GET", final_url)
response = conn.getresponse()
raw_data = response.read()
data = json.loads(raw_data)

asteroid_count = 0

for date in data['near_earth_objects'] :
	for asteroid in data['near_earth_objects'][date] :
		if (asteroid["estimated_diameter"]["meters"]["estimated_diameter_min"] >= min_diameter) and (asteroid["estimated_diameter"]["meters"]["estimated_diameter_max"] <= max_diameter) :
			asteroid_count = asteroid_count + 1



print(asteroid_count)