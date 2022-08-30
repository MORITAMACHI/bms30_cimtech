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
            $ordered->setUser($rows['user']);
            $ordered->setQuantity($rows['quantity']);
            $ordered->setDate($rows['date']);

            $orderedArray[] = $ordered;
        }
         //結果保持用メモリを開放する　追記：08/24,Takeda
         mysqli_free_result($result);
        return $orderedArray;
    }
}

?>
