


<?php
	
	$fp=fopen('formdata.txt','w+');
	$numberOfEntry=$_POST['numberOfEntry'];
	
	
	for($i=0;$i<$numberOfEntry;$i++)
	{
		  
		
		if($_POST["Square_$i"])
		{
			echo $_POST["Square_$i"]; 
			$savestring='1'.' '.$_POST["leng_$i"].' '.$_POST["brea_$i"]."\n";
			echo "<h1>$savestring</h1>";
			fwrite($fp, $savestring);
		}
		elseif (isset($_POST["Rectangle_$i"])) {
			# code...
			echo $_POST["Rectangle_$i"];
			$savestring='2'.' '.$_POST["leng_$i"].' '.$_POST["brea_$i"]."\n";
			echo "<h1>$savestring</h1>";
			fwrite($fp, $savestring);
		}
		
	}
	fclose($fp);
	echo "<h1>You data has been saved in a text file!</h1>";
?>