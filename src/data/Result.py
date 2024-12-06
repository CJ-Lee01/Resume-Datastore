class CommandResult:
  
  def print():
    pass 

class ErrorResult(CommandResult):
  def __init__(self, err: Exception, message: str) -> None:
    super().__init__()
    self.err = err 
    self.message = message

  def print(self):
    print(self.message)

class SuccessResult(CommandResult):
  def __init__(self, message: str) -> None:
    super().__init__()
    self.message = message
  
  def print(self):
    print(self.message)
