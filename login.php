<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
  // collect value of input field]8-
  $name = $_POST['fname'];
  $pssword=$_POST['password'];
  $servername = "localhost";
  $username = "root";
  $password = "albert";
  $conn =  mysqli_connect($servername,$username,$password);
	if ($conn){
		$sql = "USE USER";
		if (mysqli_query($conn, $sql)) {
			echo "Database connected successfully\n";
			echo nl2br("\n");
			$sql="SELECT username,password FROM username1 WHERE username= '$name' AND password='$pssword'";
			$result = mysqli_query($conn, $sql);
   			if(mysqli_num_rows($result)>0){
       				echo "username exists";
   			}else{
       				echo "username and password mismatch";
   			} 
		} else {
			echo "Error creating database: " . mysqli_error($conn);
		}
		

	}else{
		die("Connection failed: " . mysqli_connect_error());
	}
   


}

?>
