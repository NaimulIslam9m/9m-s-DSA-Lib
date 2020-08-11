/**
    1 based indexing এর cycle এ
    ith position থেকে m position পরের index => next(i, m)
    and ith position থেকে m position আগের index => prev(i, m)
    n => size of cycle
*/
next(i, m) = ((i - 1) + m) % n + 1
prev(i, m) = ((i - 1) + n - m) % n + 1


/**
    rotate numbers
    এখানে x হচ্ছে যে নাম্বারকে প্রথমে রাখতে চাই সেটা।
*/
rotate(v.begin(), v.begin() + (find(v.begin(), v.end(), x) - v.begin()), v.end());
