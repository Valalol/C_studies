// ==UserScript==
// @name         Gestnote Ranking
// @namespace    http://tampermonkey.net/
// @version      0.2
// @description  Script to make your ranking appear on Gestnote
// @author       Julien CHATRY
// @match        https://scolarite.polytech.univ-nantes.fr
// @icon         https://i.imgur.com/R2poAjs.png
// @grant        none
// ==/UserScript==

// Function to add the ranking div
function addDiv(element, new_id, all_grades, my_grades) {
    let new_div = document.createElement("div");
    new_div.style.width = "50px";
    new_div.style.height = "16px";
    new_div.style.border = "1px solid #DDD";
    new_div.style.display = "flex";
    new_div.style.justifyContent = "center";
    new_div.innerHTML = "...";
    if (my_grades[new_id].length) {
        let rank =
            all_grades[new_id].indexOf(parseFloat(my_grades[new_id])) + 1;
        let numberGrades = all_grades[new_id].length;
        new_div.innerHTML = rank + "/" + numberGrades;
    }

    element.appendChild(new_div);
}

//Function to set all grades spans to flexboxes
function flexify(element) {
    element.style.display = "flex";
}

function add_grades_from_HTML(elements) {
    elements.forEach(function (part) {
        if (part.includes("note_")) {
            let keystart = part.indexOf("key=")
            if (part[keystart+4] == "\""){keystart = keystart+2;}
            let gradeId = part.slice(keystart+3,keystart+13);
            let gradesStrArray = part.slice(
                part.indexOf("["),
                part.indexOf("]") + 1,
            );
            let gradesArray = JSON.parse(gradesStrArray);
            gradesArray.sort((a, b) => b - a); // Sort in descending order
            let myGrade = part.slice(
                part.indexOf("setNote(") + 8,
                part.indexOf(';">') - 1,
            );
            allGrades[gradeId] = gradesArray;
            myGrades[gradeId] = myGrade;
        }
    });
}

function first_loading(){
    /*
    When the page loads for the first time, the needed information is already in the source code, so
    there is no need to fetch the data from a URL
    */

    // Get all script elements
    var scriptElements = document.querySelectorAll("script");

    // Filter script elements whose content starts with "ParseAjaxData"
    var filteredScripts = Array.from(scriptElements).filter(function (script) {
        return script.textContent.trim().startsWith("ParseAjaxTextData");
    });

    // Split for each grade
    var gradesScript = filteredScripts[0].innerHTML;
    const separatedScript = gradesScript.split("key");

    // Create a dict with ids as keys, array of grades as value, and one with your own grades
    add_grades_from_HTML(separatedScript);

    display_ranks();
}

function display_ranks(){

    // Get all div elements with id starting with "note"
    var noteDivs = document.querySelectorAll('div[id^="note_"]');

    // Filter div elements with ids ending with exactly 5 digits
    var filteredDivs = Array.from(noteDivs).filter(function (div) {
        return /e_\d{5}$/.test(div.id);
    });

    // Get the current width as a number
    var currentDivsWidth = parseInt(window.getComputedStyle(filteredDivs[0]).width);

    // Reduce the width by 10 pixels
    var newDivsWidth = currentDivsWidth - 30;

    // Reduce all previously found divs' width by 20px
    filteredDivs.forEach((div) => (div.style.width = newDivsWidth + "px"));

    // Get the parents of each div in the array
    var parentDivs = Array.from(filteredDivs).map(function (div) {
        return div.parentNode;
    });

    // Loop through the collected parent elements and make them flexboxes
    parentDivs.forEach((div) => flexify(div));

    // Loop through the collected parent elements
    for (let i = 0; i < parentDivs.length; i++) {
        addDiv(parentDivs[i], filteredDivs[i].id, allGrades, myGrades);
    }
}

// Function to fetch data when an option is selected
function fetchData() {
    // Retrieve the value of the selected option
    var maqValue = maqSelect.value;
    var dptValue = dptSelect.value;

    // URL for the request with selectedValue
    var url = "https://scolarite.polytech.univ-nantes.fr/gestnote/?fct=bulletin&maq=" + maqValue + "&dpt=" + dptValue;

    // Fetch data from the URL
    fetch(url)
        .then(response => response.text())
        .then(data => {
            // Extract the desired data from the response
            var parser = new DOMParser();
            var xmlDoc = parser.parseFromString(data, "text/xml");
            var addhelpElements = xmlDoc.getElementsByTagName("addhelp");

            addhelpElements = Array.from(addhelpElements).map(function (element) {
                 return element.outerHTML;
            });

            add_grades_from_HTML(addhelpElements);
            display_ranks();

        })
        .catch(error => {
            console.error('Error:', error);
        });
}

// Get the select elements by ID
var maqSelect = document.getElementById("maq");
var dptSelect = document.getElementById("dpt");

// Attach an event listener to the select elements
maqSelect.addEventListener("change", fetchData);
dptSelect.addEventListener("change", fetchData);

var myGrades = {};
var allGrades = {};

first_loading();
