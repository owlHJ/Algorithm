import sys
input=sys.stdin.readline

n,m=map(int,input().split())# 공백을 기준으로 입력받기
arr= list(map(int,input().split()))
#list-> 연속된(배열), 
#map->묶을꺼야 int러 구성된 띠어쓰기 입력값
prefix_sum=[0]

temp =0
for i in arr:
  temp +=i
  prefix_sum.append(temp)
  
for i in range(m):
  a,b=map(int,input().split())
  print(prefix_sum[b]-prefix_sum[a-1])
  
  