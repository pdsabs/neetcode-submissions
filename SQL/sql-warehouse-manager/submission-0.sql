-- Write your query below
SELECT name AS warehouse_name, COALESCE(SUM(width*length*height*units), 0) AS volume
FROM warehouse wa
JOIN products pr ON wa.product_id = pr.product_id
GROUP BY wa.name