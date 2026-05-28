# 读取输入
word = input().strip()
article = input()

# 统一转小写
target = word.lower()
s = article.lower()

# 分割成单词列表（自动处理连续空格）
words = s.split()
count = 0
first_idx = -1  # 第一次出现的单词序号

# 遍历统计
for i in range(len(words)):
    if words[i] == target:
        count += 1
        if first_idx == -1:
            first_idx = i

if count == 0:
    print(-1)
else:
    # 计算原始文章中第一个匹配单词的首字符索引
    # 找到前first_idx个单词总长度 + 空格数
    pos = 0
    for i in range(first_idx):
        pos += len(words[i]) + 1  # +1是单词后的空格
    print(count, pos)