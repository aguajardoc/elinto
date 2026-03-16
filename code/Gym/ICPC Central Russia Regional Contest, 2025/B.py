# Problem: B. Old Tetris
# Contest: Codeforces - ICPC Central Russia Regional Contest, 2025
# URL: https://codeforces.com/gym/106189/problem/B
# Memory Limit: 256 MB
# Time Limit: 1000 ms
# 
# Powered by CP Editor (https://cpeditor.org)
x = int(input())

n = 0

l = 0
r = x

while l <= r:
	m = (l + r) // 2
	
	fm = 50 * m * m + 20 * m
	
	if (fm <= x):
		n = max(n, m)
		l = m + 1
	else:
		r = m - 1
	

level = 2 * n
inc = level * 10 + 10

points = 50 * n * n + 20 * n

# print(points)

tetrises = 0

while (points < x):
	points += inc
	tetrises += 1
	
	if (tetrises == 3 or tetrises == 5):
		inc += 10
		level += 1

print(f"{level} {points}")