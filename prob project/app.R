library(shiny)
library(shinyjs)

# Load the UI and server modules
source("ui.r")
source("server.r")

# Run the Shiny app
shinyApp(ui, server)
