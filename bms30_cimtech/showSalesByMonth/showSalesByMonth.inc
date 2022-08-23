<?php
/*
 *  売り上げ状況確認
 *  めも：データベースから年月でデータを検索
 */
header("Content-type: text/html; charset=UTF-8");

class uriage_model {

    function showSales($db){
        if(isset($_POST['sales'])){ //売り上げ表示ボタン押下時

            $date = $_POST['date']; //yyyy-MMの形で取得

            // SQL(該当の年月（ISBN、書籍名、価格、小合計、売り上げ）のみ取得）
            $sql = "SELECT o.isbn, b.title, b.price, SUM(o.quantity) as totalQuantity,
                 (b.price * SUM(o.quantity)) as subTotalSales FROM bookinfo b, orderinfo o
                 WHERE b.isbn = o.isbn AND (DATE_FORMAT(date,'%Y-%m') = '{$date}') GROUP BY o.isbn";


            // データベースから結果を取得
            $result = executeQuery($db,$sql);

            if($result){
               while($row = mysqli_fetch_array($result)){

                    $sales = new Sales();

                    $sales->setIsbn($row['isbn']);
                    $sales->setTitle($row['title']);
                    $sales->setPrice($row['price']);
                    $sales->setTotalQuantity($row['totalQuantity']);
                    $sales->setSubTotalSales($row['subTotalSales']);

                    $salesArray[] = $sales;
                }

                return $salesArray;
            }else{
                return false;
            }
        }
    }

    /**
     * 概要：月の総売上を返すヨ
     */
    function total ($array){
        $total = 0;
        if(isset($array)){
            foreach ($array as $val){

                // $val：オブジェクト
                $total += $val->getSubTotalSales();
            }
            return $total;

        } else {
            return false;
        }

    }
}
?>
