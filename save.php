<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
  // collect value of input field]8-
  $name = $_POST['fname'];
  $pssword=$_POST['password'];
  var_dump($name);
  $servername = "localhost";
  $username = "root";
  $password = "albert";
  $conn =  mysqli_connect($servername,$username,$password);
	if ($conn){
		$sql = "USE USER";
		if (mysqli_query($conn, $sql)) {
			echo "Database connected successfully\n";
		} else {
			echo "Error creating database: " . mysqli_error($conn);
		}
		$sql = "INSERT INTO username1 (username,password) VALUES('$name','$pssword')";
		if (mysqli_query($conn, $sql)) {
			echo "Registered successfully";
		} else {
			echo "Error creating entry Duplicate Entry found please use a different username " . mysqli_error($conn);
		}


	}else{
		die("Connection failed: " . mysqli_connect_error());
	}


}

?>

