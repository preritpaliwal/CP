import math
def calculate_probability(M, V, W):
    min = -100000
    max = -min
    st_dev = math.sqrt(V)
    if W>M+10*st_dev:
        return 0
    sum = 0
    sample = 100000
    step = (M+10*st_dev - W)/sample
    for i in range(sample):
        sum += math.exp(-((W + i*step-M)**2)/(2*V))/math.sqrt(2*3.14*V)
        print(sum)
    ans = sum/(sample)
    return ans
print(calculate_probability(0,2,-20))