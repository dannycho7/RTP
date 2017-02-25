Representative Two-Phase Search (RTP)
=======================================
Release note: [March, 2017]
-----------------

Project overview:
-----------------
A Representative guided Two-Phase as Described in [1]. The package takes an input in the XML format. The framework uses C++ and lucene to index and search the dataset.

Package overview:
-----------------

src/: source code files.

target/: compiled code, intermediate files and Final Search Result.

data/: contains a toy-dataset of Wikipedia in the XML format. 

Quick start:
------------

1) Clone the repository as: git clone https://github.com/mynameisverylong/RTP.git

2) Make sure GCC and G++(C++11) compilers are installed in the system.

3) Install libxml++ (a C++ API for the popular libxml XML parser)[http://libxmlplusplus.sourceforge.net/docs/manual/html/index.html#id2540799]. You can check the installation by running: `pkg-config libxml++-2.6 --cflags --libs` 

4) Make sure that the OpenSSL in installed on your machine.

5) To compile:

`make`

6) To index the data

`./index.sh <data_file_path> <choice_of_representative>`

Possible choices for &lt;choice_of_representative&gt; are:

	1: for latest representative

	2: for longest representative

7) To run queries: Enter all the queries (1 per line) in a .txt file and run the following command:

`./run_batch.sh <query_file>`

Dataset Format:
------------
The dataset has to be in the following format:
<pre><code>&lt;data&gt;
   &lt;version&gt;
        &lt;page&gt;
             &lt;title&gt;...&lt;/title&gt;
             &lt;content&gt;...&lt;/content&gt;
        &lt;/page&gt;
        .
        .
        .
   &lt;/version&gt;
   .
   .
   .
&lt;/data&gt;</code></pre>

Explanation:

All the data needs to be wrapping within a &lt;data&gt; tag. The data is organized into versions and each version of the data is placed within a &lt;version&gt; tag. Each &lt;page&gt; contains a page (i.e., a document) that belongs to the current version. If the page (i.e., a document) does not contain the current version represented by the &lt;version&gt; tag, then it can be skipped.  Each page is represented with a title and content using the &lt;title&gt; and &lt;content&gt; tag respectively.

References:
-----------

[1]  "Hybrid Indexing for Versioned Document Search with Cluster-based Retrieval". Xin Jin, Daniel Agun, Tao Yang, Qinghao Wu, Yifan Shen, Susen Zhao. ACM CIKM, October 2016.
