# hint

when using this the function is called answer(with a url in here) this should return your answer. Understand we are using specific URLS from stack Exchange API so if its not a particular URL it will not work.
Here is an examplel URL only thing that should change is the question

api.stackexchange.com/2.2/search?order=desc&sort=activity&intitle=close vim&site=stackoverflow&filter=!)QiKXv6_VRyxawI7)5Lo)ptD

if you lok at the link where you see =close vim& thats the question so if you want to find the asnwer for opening vim it would look like this

api.stackexchange.com/2.2/search?order=desc&sort=activity&intitle=open vim&site=stackoverflow&filter=!)QiKXv6_VRyxawI7)5Lo)ptD
or if that gives CURL bad URL do

api.stackexchange.com/2.2/search?order=desc&sort=activity&intitle=open%20vim&site=stackoverflow&filter=!)QiKXv6_VRyxawI7)5Lo)ptD

I Added %20 between each word of the question that is being asked, CURL can sometimes be finicky with thsi but during testing worked 95% of the time without the %20

