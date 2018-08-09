http://www.iro.umontreal.ca/~lisa/twiki/bin/view.cgi/Public/MnistVariations
All the datasets are provided as zip archives. Each archive contains two files -- a training (and validation) set and a test set. 
We used the last 2000 examples of the training sets as validation sets and, in the case of SVMs, 
retrained the models with the entire set after choosing the optimal parameters on these validation sets. 
Data is stored at one example per row, the features being space-separated. There are 784 features per example (=28*28 images), 
corresponding to the first 784 columns of each row. 
The last column is the label, which is 0 to 9. 