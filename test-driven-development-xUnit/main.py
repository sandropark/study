class WasRun:
    def __init__(self, name):
        self.was_run = None

    pass

    def test_method(self):
        pass


test = WasRun("testMethod")
print(test.was_run)
test.test_method()
print(test.was_run)