# Easy
* 愚直に見ていった．sのindexを外部に保持して，tを順番に探した．
* t8m8さんはlcsで求めた(早い)

# Mid
* d-t+t^2 が正となる最大のtを求める．
* 2分探索
* 普通に計算するとlonglongをオーバーするが，今回tが最大でも10^9なのでr=10^9として2分探索すれば良い．
* tがどれだけかをまず見る.