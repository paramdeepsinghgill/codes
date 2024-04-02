from wordcloud import WordCloud
import matplotlib.pyplot as plt

# Sample text data
text = "Hello world hello Python world Python world"

# Generate word cloud
wordcloud = WordCloud(width=800, height=400, background_color='white').generate(text)

# Display the word cloud using matplotlib
plt.figure(figsize=(10, 5))
plt.imshow(wordcloud, interpolation='bilinear')
plt.axis('off')
plt.show()