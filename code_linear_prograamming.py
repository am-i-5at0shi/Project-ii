from pulp import LpMaximize,LpProblem,LpStatus,lpSum,LpVariable
model = LpProblem(name="",sense=LpMaximize)
x = LpVariable(name="x", lowBound=0)
y = LpVariable(name="y", lowBound=0)
model += (2 * x +  y <= 20, "red_constraint")
model += ((-4) * x + 5 * y <= 10, "blue_constraint")
model += (-x + 2 * y >= -2, "yellow_constraint")
obj_func = x + 2 * y
model += obj_func
status = model.solve()
print(">>>",model)
print("------------------------------------------------")
coeff = [1, 2]
i=0;
z=0;
for var in model.variables():
	print("X",i+1,"= ",var.value(),sep="")
	z+=coeff[i]*var.value()
	i+=1
print("max(z)=",z)
