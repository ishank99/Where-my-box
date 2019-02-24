  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.0/css/bootstrap.min.css">
  <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.3.1/jquery.min.js"></script>
  <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.0/js/bootstrap.min.js"></script>
  <body style = "background-image:linear-gradient(to left, red, orange);" >
<?php 
$numberOfEntry=$_POST["Quantity"];
echo "<form action='main.php' method='POST' >";
for($i=0;$i<$numberOfEntry;$i++)
{ 
	
    echo "<div class='='checkbox' style ='padding-left: 30px;'>
      <label><input type='checkbox' name='Square_$i'> Square</label>
    </div>
    <div class='checkbox' style ='padding-left: 30px;'>
      <label><input type='checkbox' name='Rectangle_$i'> Rectangle</label>
    </div>
    

    <div class'form-group' style ='padding-left: 30px;'>
      <label for='email'>Length: <input type='number' min=0 class='form-control' id='email' placeholder='Enter length' name='leng_$i'></label>
    </div>
    <div class='form-group' style = 'padding-left: 30px;'>
      <label for='pwd'>Breadth:
      <input type='number' min=0 class='form-control' id='pwd' placeholder='Enter width' name='brea_$i'></label>
    </div>
    <hr>"
    
?>   
  

<!-- 
	<input type='checkbox' name='Square_$i'>Square</label>
	
	<input type='checkbox' name='Rectangle_$i'>Rectangle</label>
	
	<h3>Enter Length</h3>
	
	<input type='Number' name='leng_$i'> 
	
	<h3>Enter Breadth</h3>
	
	<input type='Number' name='brea_$i'> 
	<br/>
	<br/>
	<br/>
	<br/> -->
	<?php
}
echo"<input type='hidden' name='numberOfEntry' value='$numberOfEntry'>";
echo " <input type='submit' value='Submit'>";
echo "</form>";
?>
</body>
