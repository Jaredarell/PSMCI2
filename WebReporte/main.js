const ctx1 = document.getElementById("myChart").getContext('2d');
const printCharts = () => {
    renderModelChart()
}

const renderModelChart = () => {
    const data = {
        labels: ["Conradin", "Jared", "Manolo", 'Memin', 'Gatita'],
        datasets: [{
            data: [10,11,30, 5, 19]

        }]
    }
    new Chart('modelschart', {type: 'line', data})
    new Chart('modelschartTwo', {type: 'line', data})
}

printCharts()

const area = ["A1", "A2", "B1", "B2"]
const temperature = [19.4, 27.3, 50.9, 37.5]

const myChart = new Chart(ctx1, {
    type: "line",
    data: {
        labels: "area",
        datasets: [{
            label: "temperatura",
            data: temperature,
            backgroundColor:[
                "rgba(255, 99, 132, 0.2)",
                "rgba(54, 162, 235, 0.2)",
                "rgba(75, 192, 192, 0.2)",
                "rgba(153, 102, 255, 0.2)",
            ],
            borderColor:[
                "rgba(255, 99, 132, 1)",
                "rgba(54, 162, 235, 1)",
                "rgba(75, 192, 192, 1)",
                "rgba(153, 102, 255, 1)",
            ]

        }],
        borderWidth: 1.5
    }
})
