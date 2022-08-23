<?php
//=====================================================================================
// プログラム名  ：注文MVCモデル
// プログラム説明：注文状況確認の際に使用するDTOファイル
// 作成者        ：たけだりほ
// 作成日        ：2022/08/18
//=====================================================================================
class Ordered{
    //--------------------------------------
    //各フィールド変数宣言
    //--------------------------------------
    private $orderno;						//注文No
    private $user;						//ユーザーID
    private $isbn;						//ISBN
    private $quantity;						//数量
    private $date;							//購入日付

    /*
     * 08/23 たけだ追記
     */
    private $title;

    public function getTitle()
    {
        return $this->title;
    }

    public function setTitle($title)
    {
        $this->title = $title;
    }

    /**
     * @return number
     */
    public function getOrderno()
    {
        return $this->orderno;
    }

    /**
     * @return string
     */
    public function getUser()
    {
        return $this->user;
    }

    /**
     * @return string
     */
    public function getIsbn()
    {
        return $this->isbn;
    }

    /**
     * @return number
     */
    public function getQuantity()
    {
        return $this->quantity;
    }

    /**
     * @return string
     */
    public function getDate()
    {
        return $this->date;
    }

    /**
     * @param number $orderno
     */
    public function setOrderno($orderno)
    {
        $this->orderno = $orderno;
    }

    /**
     * @param string $userid
     */
    public function setUser($user)
    {
        $this->user = $user;
    }

    /**
     * @param string $isbn
     */
    public function setIsbn($isbn)
    {
        $this->isbn = $isbn;
    }

    /**
     * @param number $quentity
     */
    public function setQuantity($quentity)
    {
        $this->quantity = $quentity;
    }

    /**
     * @param string $date
     */
    public function setDate($date)
    {
        $this->date = $date;
    }

    /**
     *   概要：__construct
     *   機能説明：コンストラクタ
     */
    public function __construct(){
        $this->init();
    }

    /**
     *   概要：init
     *   機能説明：フィールド変数初期化
     */
    public function init() {
        $this->orderno	 = 0 ;				//注文No
        $this->user	 = '' ;				//ユーザーID
        $this->isbn	 = '' ;				//ISBN
        $this->quantity	 = 0;				//数量
        $this->date		 = '';				//購入日付

    }

    /**
     *  概要
     *  機能説明：購入情報をもとに登録を行う
     *  @return boolean
     */
   public function insert(){

       // コンストラクタを呼び出す必要はない

        $sql = "INSERT INTO orderinfo VALUES(NULL,'"+getUserid()+"','"+getIsbn()+"',"
        +getQuantity()+",CURDATE()";

        $result = executeQuery($sql);

        if (mysqli_num_rows($result) == 1) {
            // データベース登録に成功した時
            return true;
        } else {
            return false;
        }
    }
}
?>
