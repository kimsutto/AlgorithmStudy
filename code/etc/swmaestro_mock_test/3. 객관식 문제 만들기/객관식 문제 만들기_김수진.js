function submit () {
	var checkBoxArr = new Array();
	
	var chk_obj = document.getElementsByName("box_chk");

	for(var i=0; i<5; i++){
		if(chk_obj[i].checked==true){
			checkBoxArr.push(chk_obj[i].value);
		}
	}
	
	fetch('/submit', {
		method: 'POST',
		headers: {'Content-Type': 'application/json'},
		body: JSON.stringify({answers : checkBoxArr})
	})
		.then(res => res.json())
		.then(response => {
				if(response){
						document.getElementById("result").innerText="정답입니다.";
				}else {
						document.getElementById("result").innerText="오답입니다.";
				}
	})			
		.catch(error => console.log(error));
};
