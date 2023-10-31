import matplotlib.pyplot as plt

input = ""
output = []
vars = []

with open('output.txt', 'r') as file:
    
    input = file.readline()

    N = int(file.readline())

    for i in range(N):
        
        var = float(file.readline())
        vars.append(var)
        M = int(file.readline())
        output.append([])
        for j in range(M):
            output[i].append(str(file.readline()))
    

plotdata_vars = []
plotdata_probs = []


for i in range(len(vars)):
    
    misscount = 0

    for j in range(len(output[i])):
        
        for k in range(len(output[i][j])):
            
            if output[i][j][k] != input[k]:
                misscount += 1

    probability = misscount / len(output[i] * len(input))
    plotdata_vars.append(vars[i])
    plotdata_probs.append(probability)
    

plt.figure(figsize=(8, 6))
plt.plot(plotdata_vars, plotdata_probs, marker='o', linestyle='-', color='b')
plt.xlabel('STD') 
plt.ylabel('error per bit') 
plt.title('График зависимости вероятности ошибки от дисперсии шума')
plt.grid(True)

plt.savefig('QAM64.png')

plt.show()