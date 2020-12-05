
class Environment:

	def __init__(self,m,n,goal_x,goal_y):
		self.m=m
		self.n=n
		self.goal_x=goal_x
		self.goal_y=goal_y

	def getgrid_x(self):
		return self.m
	def getgrid_y(self):
		return self.n
	def getgoalposition_x(self):
		return self.goal_x

	def getgoalposition_y(self):
		return self.goal_y

class Agent:

	def __init__(self,agent_pos_x,agent_pos_y):
		self.agent_pos_x=agent_pos_x
		self.agent_pos_y=agent_pos_y

	def getpositionsensor_x(self):
		return self.agent_pos_x

	def getpositionsensor_y(self):
		return self.agent_pos_y 

	def valid_move(self,e):

		x=abs(e.getgoalposition_x()-self.agent_pos_x)
		y=abs(e.getgoalposition_y()-self.agent_pos_y)
		if x>e.getgrid_x() & y>e.getgrid_y() :
			return 0
		else:
			return 1

	def moveright(self):
		self.agent_pos_x=self.agent_pos_x+1

	def moveleft(self):
		self.agent_pos_x=self.agent_pos_x-1

	def moveup(self):
		self.agent_pos_y=self.agent_pos_y+1

	def movedown(self):
		self.agent_pos_y=self.agent_pos_y-1

	def tot_distance(self,e):
		tot_x=abs(e.getgoalposition_x()-self.agent_pos_x)
		tot_y=abs(e.getgoalposition_y()-self.agent_pos_y)
		return (tot_x+tot_y)

	def printdir(self,dir):
		print(dir ,(self.agent_pos_x ,self.agent_pos_y))

	def findpath(self,e):

		goal_x=e.getgoalposition_x()
		goal_y=e.getgoalposition_y()

		while goal_x>self.agent_pos_x:
			self.moveright()
			self.printdir("R")

		while goal_x<self.agent_pos_x:
			self.moveleft()
			self.printdir("L")

		while goal_y>self.agent_pos_y:
			self.moveup()
			self.printdir("U")

		while goal_y<self.agent_pos_y:
			self.movedown()
			self.printdir("D")

	def right_check(self,e,distance):
		self.moveright()
		if distance>self.tot_distance(e):
			distance=self.tot_distance(e)
			self.printdir("R")
		else:
			self.moveleft()

		return distance

	def left_check(self,e,distance):
		self.moveleft()
		if distance>self.tot_distance(e):
			distance=self.tot_distance(e)
			self.printdir("L")
		else:
			self.moveright()

		return distance

	def up_check(self,e,distance):
		self.moveup()
		if distance>self.tot_distance(e):
			distance=self.tot_distance(e)
			self.printdir("U")
		else:
			self.movedown()

		return distance

	def down_check(self,e,distance):
		self.movedown()
		if distance>self.tot_distance(e):
			distance=self.tot_distance(e)
			self.printdir("D")
		else:
			self.moveup()

		return distance


	def findgoal(self,e):
		distance=self.tot_distance(e)

		while distance!=0:

			distance=self.right_check(e,distance)
			distance=self.left_check(e,distance)
			distance=self.up_check(e,distance)
			distance=self.down_check(e,distance)


print("Give the size of grid M N")
m=input()
n=input()
m=int(m)
n=int(n)

goal_x=input("Enter sound sensor x coordinate: ")
goal_y=input("Enter sound sensor y coordinate: ")
goal_x=int(goal_x)
goal_y=int(goal_y)

en=Environment(n,m,goal_x,goal_y)

agent_pos_x=input("Enter the x coordinate of agent: ")
agent_pos_y=input("Enter the y coordinate of agent: ")
agent_pos_x=int(agent_pos_x)
agent_pos_y=int(agent_pos_y)
ag=Agent(agent_pos_x,agent_pos_y)


if ag.valid_move(en):
	ag.findgoal(en)
else:
	print("Cant reach the goal")



