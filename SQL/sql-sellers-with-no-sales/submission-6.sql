-- Write your query below
Select seller_name from seller
    where seller_id not in (
        Select seller_id from orders
        where sale_date >= '2020-01-01' AND sale_date < '2021-01-01'
    ) Order by seller_name ASC;