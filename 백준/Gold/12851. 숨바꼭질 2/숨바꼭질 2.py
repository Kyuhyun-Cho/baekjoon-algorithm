import sys
from collections import deque


n, k = map(int, sys.stdin.readline().split())

visited = [float("inf")] * (100001)

def bfs(v):
    queue = deque()

    queue.append((v, 0))

    visited[v] = 0

    min_time = float("inf")
    cnt = 0

    while queue:
        current_pose, current_time = queue.popleft()

        # print(current_pose, current_time)
        if current_time > min_time:
            continue

        if current_pose == k:
            
            # print("!!")
            if current_time < min_time:
                # print("new", current_pose, current_time)
                min_time = current_time
                cnt = 1
            elif current_time == min_time:
                # print("add", current_pose, current_time)
                cnt += 1

        left = current_pose - 1
        right = current_pose + 1
        jump = current_pose * 2
        
        time = current_time + 1

        if 0 <= left <= 100000 and time <= visited[left]:
            queue.append((left, time))
            visited[left] = time

        if 0 <= right <= 100000 and time <= visited[right]:
            queue.append((right, time))
            visited[right] = time

        if 0 <= jump <= 100000 and time <= visited[jump]:
            queue.append((jump, time))
            visited[jump] = time
         
    return min_time, cnt


min_time, cnt = bfs(n)

print(min_time)
print(cnt)
