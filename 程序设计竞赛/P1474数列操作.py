import heapq
import sys

def main():
    for line in sys.stdin:
        n = int(line.strip())
        nums = list(map(int, sys.stdin.readline().split()))
        heapq.heapify(nums)
        while len(nums) > 1:
            a = heapq.heappop(nums)
            b = heapq.heappop(nums)
            merged = a * b + 1
            heapq.heappush(nums, merged)
        print(nums[0])

if __name__ == "__main__":
    main()