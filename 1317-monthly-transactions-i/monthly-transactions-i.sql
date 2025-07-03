-- Write your PostgreSQL query statement below

SELECT 
    to_char(t.trans_date,'yyyy-mm') as month,
    t.country,
    COUNT(*) AS trans_count,
    COUNT(CASE WHEN t.state = 'approved' THEN 1 END) AS approved_count,
    SUM(t.amount) AS trans_total_amount,
    SUM(CASE WHEN t.state = 'approved' THEN t.amount ELSE 0 END) AS approved_total_amount
FROM Transactions t
GROUP BY month, t.country
ORDER BY month, t.country;