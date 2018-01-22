import requests

date1 = str(input())
date2 = str(input())
min_diameter = float(input())
max_diameter = float(input())

#final_url = "https://api.nasa.gov/neo/rest/v1/feed?start_date="+date1+"&end_date="+date2+"&api_key=K31zU0mautN92seqieFg929manLx0pUQ6QDFGDNp"
final_url = "https://api.nasa.gov/neo/rest/v1/feed?start_date=2015-09-07&end_date=2015-09-08&api_key=K31zU0mautN92seqieFg929manLx0pUQ6QDFGDNp"
r = requests.get(final_url)
data = r.json()
print(type(data))
print(len(data.keys()))
print(data)
if 'links' in data :
    print('On my way')

asteroid_count = 0

for date in data['near_earth_objects'] :
	for asteroid in data['near_earth_objects'][date] :
		if (asteroid["estimated_diameter"]["meters"]["estimated_diameter_min"] >= min_diameter) and (asteroid["estimated_diameter"]["meters"]["estimated_diameter_max"] <= max_diameter) :
			asteroid_count = asteroid_count + 1
print(asteroid_count)
