<?php
class OrderStatus{

    //購入情報取得
    public function OrderedSearch($db){

        $sql = "SELECT * FROM orderinfo inner join bookinfo on orderinfo.isbn = bookinfo.isbn";

        $result = executeQuery($db, $sql);
        $rows = mysqli_num_rows($result);

        while($rows = mysqli_fetch_array($result)){

            $ordered = new Ordered();

            $ordered->setTitle($rows['title']);
            $ordered->setUser($rows['userid']);
            $ordered->setQuantity($rows['quantity']);
            $ordered->setDate($rows['date']);

            $orderedArray[] = $ordered;
        }
        return $orderedArray;
    }
}

?>